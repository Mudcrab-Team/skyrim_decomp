param(
    [Parameter(Mandatory)]
    [ValidateSet('install-task', 'start', 'run', 'status', 'stop')]
    [string] $Action,
    [ValidatePattern('^[a-f0-9]{32}$')]
    [string] $Session
)
$ErrorActionPreference = 'Stop'
$taskName = 'SkyrimDevTools'
$root = $PSScriptRoot
$games = Join-Path $root 'game'
$profile = Join-Path $root 'profile'
$runs = Join-Path $root 'runs'
$lease = Join-Path $root 'active'
$pin = '846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f'
$account = [Security.Principal.WindowsIdentity]::GetCurrent().Name

function Read-Json($Path) {
    Get-Content -LiteralPath $Path -Raw | ConvertFrom-Json
}

function Write-Json($Value, $Path) {
    $temporary = "$Path.new"
    [IO.File]::WriteAllText($temporary, ($Value | ConvertTo-Json -Compress))
    if ([IO.File]::Exists($Path)) {
        [IO.File]::Replace($temporary, $Path, [NullString]::Value)
    } else {
        [IO.File]::Move($temporary, $Path)
    }
}

function Result($Phase, $Reason = '', $ExitCode = $null) {
    @{ sessionId = $Session; phase = $Phase; reason = $Reason; exitCode = $ExitCode }
}

function Assert-PrivateDirectory($Path) {
    $entry = Get-Item -LiteralPath $Path
    if (!$entry.PSIsContainer -or ($entry.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
        throw 'Managed directory must be a real directory in the scratch tree'
    }
}

function Refuse-Launch($Check, $Message) {
    $failure = [InvalidOperationException]::new($Message)
    $failure.Data['LaunchCheck'] = $Check
    throw $failure
}

function Assert-InteractiveDesktop {
    # A scheduled task can still run in a disconnected desktop session.
    Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
using System.Text;

public static class SkyrimDevToolsDesktop
{
    [DllImport("wtsapi32.dll", EntryPoint = "WTSQuerySessionInformationW")]
    private static extern bool QuerySession(IntPtr server, int session, int infoClass, out IntPtr value, out int bytes);
    [DllImport("wtsapi32.dll", EntryPoint = "WTSFreeMemory")]
    private static extern void FreeSessionMemory(IntPtr value);
    [DllImport("user32.dll")]
    private static extern IntPtr OpenInputDesktop(uint flags, bool inherit, uint access);
    [DllImport("user32.dll", EntryPoint = "GetUserObjectInformationW", CharSet = CharSet.Unicode)]
    private static extern bool DesktopInfo(IntPtr desktop, int index, StringBuilder value, int bytes, out int needed);
    [DllImport("user32.dll")]
    private static extern bool CloseDesktop(IntPtr desktop);

    public static bool IsActive(int session)
    {
        const int ConnectState = 8;
        const int Active = 0;
        IntPtr value;
        int bytes;
        if (session <= 0 || !QuerySession(IntPtr.Zero, session, ConnectState, out value, out bytes))
            return false;
        try { return bytes >= sizeof(int) && Marshal.ReadInt32(value) == Active; }
        finally { FreeSessionMemory(value); }
    }

    public static bool IsUnlocked()
    {
        const uint ReadObjects = 1;
        const int Name = 2;
        IntPtr desktop = OpenInputDesktop(0, false, ReadObjects);
        if (desktop == IntPtr.Zero)
            return false;
        try {
            var name = new StringBuilder(64);
            int bytes;
            return DesktopInfo(desktop, Name, name, name.Capacity * sizeof(char), out bytes) &&
                   String.Equals(name.ToString(), "Default", StringComparison.OrdinalIgnoreCase);
        } finally { CloseDesktop(desktop); }
    }
}
'@
    $sessionId = (Get-Process -Id $PID).SessionId
    if (![SkyrimDevToolsDesktop]::IsActive($sessionId)) {
        Refuse-Launch 'desktop-inactive' 'The test account must have an active interactive desktop session'
    }
    if (![SkyrimDevToolsDesktop]::IsUnlocked()) {
        Refuse-Launch 'desktop-locked' 'The interactive test desktop is locked or inaccessible'
    }
}

function Assert-LocalProfile {
    $docs = [Environment]::GetFolderPath('MyDocuments')
    $link = Get-Item -LiteralPath (Join-Path $docs 'My Games\Skyrim Special Edition')
    $destination = @($link.Target)
    if ($link.LinkType -ne 'Junction' -or $destination.Count -ne 1 -or
        [IO.Path]::GetFullPath($destination[0]) -ne $profile) {
        throw 'The interactive test account needs an isolated Skyrim profile junction'
    }
    Assert-PrivateDirectory $profile
    Assert-PrivateDirectory (Join-Path $profile 'Saves')
    foreach ($name in @('Skyrim.ini', 'SkyrimPrefs.ini')) {
        $ini = Get-Item -LiteralPath (Join-Path $profile $name)
        if ($ini.Attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw 'Test settings must be private copies'
        }
    }
    $settings = Get-Content -LiteralPath (Join-Path $profile 'SkyrimPrefs.ini') -Raw
    foreach ($key in @('bSaveOnPause', 'bSaveOnRest', 'bSaveOnTravel', 'bSaveOnWait')) {
        $lines = [regex]::Matches($settings, "(?im)^\s*$key\s*=\s*([^\r\n]+)")
        if ($lines.Count -ne 1 -or $lines[0].Groups[1].Value.Trim() -ne '0') {
            throw 'Test profile must disable autosaves'
        }
    }
    $localSavePath = [regex]::Matches(
        (Get-Content -LiteralPath (Join-Path $profile 'Skyrim.ini') -Raw),
        '(?im)^\s*sLocalSavePath\s*=\s*([^\r\n]+)')
    if ($localSavePath.Count -ne 1 -or $localSavePath[0].Groups[1].Value.Trim() -ne 'Saves\') {
        throw 'Test profile must use its private Saves directory'
    }
}

function Assert-OfflineSteam {
    $steam = @(Get-Process steam -ErrorAction SilentlyContinue |
        Where-Object SessionId -EQ (Get-Process -Id $PID).SessionId)
    if ($steam.Count -ne 1 -or !$steam[0].Path) {
        Refuse-Launch 'steam-unavailable' 'Steam must already be running on the interactive test desktop'
    }
    try {
        $login = Get-Content -LiteralPath (Join-Path (Split-Path $steam[0].Path) 'config\loginusers.vdf') -Raw
    } catch {
        Refuse-Launch 'steam-offline-unconfirmed' 'Steam Offline Mode could not be confirmed'
    }
    $accountId = (Get-ItemProperty -LiteralPath 'HKCU:\Software\Valve\Steam\ActiveProcess' -ErrorAction SilentlyContinue).ActiveUser
    $active = @([regex]::Matches($login, '"([0-9]{1,19})"\s*\{([^{}]*)\}') |
        Where-Object { $accountId -and ([uint64]$_.Groups[1].Value % 4294967296) -eq $accountId })
    if ($active.Count -ne 1 -or $active[0].Groups[2].Value -notmatch '"WantsOfflineMode"\s+"[01]"') {
        Refuse-Launch 'steam-offline-unconfirmed' 'The active Steam account could not be confirmed'
    }
    if ($active[0].Groups[2].Value -notmatch '"WantsOfflineMode"\s+"1"') {
        Refuse-Launch 'steam-online' 'The active Steam account must be in Offline Mode'
    }
}

function Find-OwnedGame($LoaderPid) {
    Get-CimInstance Win32_Process -Filter "Name = 'SkyrimSE.exe' AND ParentProcessId = $LoaderPid" |
        Where-Object ExecutablePath -EQ (Join-Path $games 'SkyrimSE.exe') |
        Select-Object -First 1
}

function Preflight($Config) {
    Assert-InteractiveDesktop
    Assert-OfflineSteam
    if ($Config.cloudSyncDisabled -ne $true) {
        Refuse-Launch 'steam-cloud-unconfirmed' 'Disable Steam Cloud for Skyrim and confirm it in the local configuration'
    }
    if ($Config.port -isnot [int] -or $Config.port -lt 1024 -or $Config.port -gt 65535) {
        throw 'Set a valid loopback server port'
    }
    if (Get-Process SkyrimSE, skse64_loader -ErrorAction SilentlyContinue) {
        throw 'A game or loader process is already running'
    }
    Assert-LocalProfile
    Assert-PrivateDirectory $games
    $data = Join-Path $games 'Data'
    $skse = Join-Path $data 'SKSE'
    $plugins = Join-Path $skse 'Plugins'
    foreach ($directory in @($data, $skse, $plugins)) {
        Assert-PrivateDirectory $directory
    }
    $image = Join-Path $games 'SkyrimSE.exe'
    if ((Get-FileHash -LiteralPath $image).Hash -ne $pin) {
        throw 'Staged executable does not match the pinned image'
    }
    $loader = Get-Item -LiteralPath (Join-Path $games 'skse64_loader.exe')
    if ($loader.VersionInfo.FileVersionRaw -ne [version]'0.2.3.1' -or
        !(Test-Path -LiteralPath (Join-Path $games 'skse64_1_7_104.dll') -PathType Leaf)) {
        throw 'Stage official SKSE 2.3.1 for the pinned runtime'
    }
    if (!(Test-Path -LiteralPath (Join-Path $plugins 'versionlib-1-7-104-0.bin') -PathType Leaf)) {
        throw 'The pinned Address Library table is missing'
    }
    $dlls = @(Get-ChildItem -LiteralPath $plugins -File -Filter '*.dll')
    if ($dlls.Count -ne 1 -or $dlls[0].Name -ne 'SkyrimDevTools.dll') {
        throw 'The test plugin must be the only SKSE plugin DLL'
    }
    $fixture = Join-Path $root 'fixture.ess'
    $destination = Join-Path $profile 'Saves\Fixture.ess'
    foreach ($entry in Get-ChildItem -LiteralPath (Split-Path $destination) -Force) {
        if ($entry.Name -ne 'Fixture.ess' -or $entry.PSIsContainer -or
            ($entry.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
            throw 'The scratch save directory contains an unexpected entry'
        }
    }
    Copy-Item -LiteralPath $fixture -Destination $destination -Force
    (Get-FileHash -LiteralPath $destination).Hash.ToLowerInvariant()
}

function Run-Game {
    $script:Session = [IO.File]::ReadAllText($lease)
    if ($Session -notmatch '^[a-f0-9]{32}$') { throw 'Invalid session lease' }
    $run = Join-Path $runs $Session
    $state = Join-Path $run 'state.json'
    $stop = Join-Path $run 'stop'
    $loaderProcess = $null
    $game = $null
    $phase = 'failed'
    $reason = 'preflight'
    $exitCode = $null
    $digest = $null
    try {
        if (Test-Path -LiteralPath $stop) {
            $phase = 'cancelled'
            $reason = ''
            return
        }
        $config = Read-Json (Join-Path $root 'config.json')
        $digest = Preflight $config
        $env:SKYRIM_DEVTOOLS_TOKEN = (Read-Json (Join-Path $run 'request.json')).token
        Remove-Item -LiteralPath (Join-Path $run 'request.json')
        $env:SKYRIM_DEVTOOLS_SESSION = $Session
        $env:SKYRIM_DEVTOOLS_IMAGE = $pin
        $env:SKYRIM_DEVTOOLS_PORT = $config.port
        $env:SKYRIM_DEVTOOLS_RUN_DIR = $run
        $reason = 'loader'
        $loaderProcess = Start-Process -FilePath (Join-Path $games 'skse64_loader.exe') -WorkingDirectory $games -PassThru
        $deadline = [DateTime]::UtcNow.AddSeconds(25)
        do {
            $child = Find-OwnedGame $loaderProcess.Id
            if ($child) { $game = Get-Process -Id $child.ProcessId -ErrorAction SilentlyContinue }
            if (!$game) { Start-Sleep -Milliseconds 250 }
        } until ($game -or [DateTime]::UtcNow -ge $deadline -or (Test-Path -LiteralPath $stop))
        if (!$game) { throw 'Loader did not produce a staged game process' }

        $running = Result 'running'
        $running.fixtureSha256 = $digest
        Write-Json $running $state
        $reason = 'watchdog'
        $deadline = [DateTime]::UtcNow.AddMinutes(15)
        while (!$game.WaitForExit(250)) {
            if ((Test-Path -LiteralPath $stop) -or [DateTime]::UtcNow -ge $deadline) {
                $reason = if (Test-Path -LiteralPath $stop) { 'requested' } else { 'watchdog' }
                if ($game.CloseMainWindow() -and $game.WaitForExit(12000)) { break }
                $phase = 'forced'
                return
            }
        }
        $exitCode = $game.ExitCode
        if ($exitCode -ne 0) {
            $phase = 'crashed'
            $reason = 'nonzero-exit'
        } elseif (Test-Path -LiteralPath $stop) {
            $phase = 'stopped'
            $reason = ''
        } else {
            $phase = 'exited'
            $reason = 'unrequested-exit'
        }
    } catch {
        if ($_.Exception.Data['LaunchCheck']) { $reason = $_.Exception.Data['LaunchCheck'] }
        $_.Exception.Message | Set-Content -LiteralPath (Join-Path $run 'host-error.txt') -Encoding UTF8
    } finally {
        if ($loaderProcess -and !$loaderProcess.HasExited) {
            $loaderProcess.Kill()
            $loaderProcess.WaitForExit()
        }
        if (!$game -and $loaderProcess) {
            $child = Find-OwnedGame $loaderProcess.Id
            if ($child) { $game = Get-Process -Id $child.ProcessId -ErrorAction SilentlyContinue }
        }
        if ($game -and !$game.HasExited) {
            $phase = 'forced'
            $game.Kill()
            if (!$game.WaitForExit(5000)) { throw 'Owned game process did not exit after stop' }
        }
        Remove-Item -LiteralPath (Join-Path $run 'request.json') -ErrorAction SilentlyContinue
        $final = Result $phase $reason $exitCode
        if ($digest) { $final.fixtureSha256 = $digest }
        Write-Json $final $state
        Remove-Item -LiteralPath $lease
    }
}

switch ($Action) {
    'install-task' {
        $arguments = '-NoProfile -NonInteractive -ExecutionPolicy RemoteSigned -File "{0}" run' -f $PSCommandPath
        $task = New-ScheduledTaskAction -Execute 'powershell.exe' -Argument $arguments
        $principal = New-ScheduledTaskPrincipal -UserId $account -LogonType Interactive
        $settings = New-ScheduledTaskSettingsSet -MultipleInstances IgnoreNew -ExecutionTimeLimit ([TimeSpan]::Zero) -AllowStartIfOnBatteries -DontStopIfGoingOnBatteries
        Register-ScheduledTask -TaskName $taskName -Action $task -Principal $principal -Settings $settings | Out-Null
    }
    'start' {
        New-Item -ItemType Directory -Path $runs -Force | Out-Null
        $Session = [guid]::NewGuid().ToString('N')
        $run = Join-Path $runs $Session
        $bytes = New-Object byte[] 32
        $random = [Security.Cryptography.RandomNumberGenerator]::Create()
        try { $random.GetBytes($bytes) } finally { $random.Dispose() }
        $token = [BitConverter]::ToString($bytes).Replace('-', '').ToLowerInvariant()
        $config = Read-Json (Join-Path $root 'config.json')
        if ((Get-ScheduledTask -TaskName $taskName).State -ne 'Ready') { throw 'Interactive task is busy' }
        $stream = [IO.File]::Open($lease, 'CreateNew', 'Write', 'None')
        try {
            $id = [Text.Encoding]::ASCII.GetBytes($Session)
            $stream.Write($id, 0, $id.Length)
        } finally { $stream.Dispose() }
        try {
            New-Item -ItemType Directory -Path $run | Out-Null
            Write-Json @{ token = $token } (Join-Path $run 'request.json')
            Write-Json (Result 'starting') (Join-Path $run 'state.json')
            Start-ScheduledTask -TaskName $taskName
        } catch {
            if (Test-Path -LiteralPath $run) {
                Remove-Item -LiteralPath (Join-Path $run 'request.json') -ErrorAction SilentlyContinue
                Write-Json (Result 'failed' 'scheduler') (Join-Path $run 'state.json')
            }
            Remove-Item -LiteralPath $lease
            throw
        }
        @{ sessionId = $Session; port = $config.port; token = $token } | ConvertTo-Json -Compress
    }
    'run' { Run-Game }
    'status' {
        if (!$Session) { throw 'Session id is required' }
        Get-Content -LiteralPath (Join-Path $runs "$Session\state.json") -Raw
    }
    'stop' {
        if (!$Session) { throw 'Session id is required' }
        $run = Join-Path $runs $Session
        $state = Read-Json (Join-Path $run 'state.json')
        if ($state.phase -in @('starting', 'running')) {
            [IO.File]::WriteAllText((Join-Path $run 'stop'), '')
        }
        if ($state.phase -eq 'starting' -and (Get-ScheduledTask -TaskName $taskName).State -eq 'Ready' -and
            (Test-Path -LiteralPath $lease) -and [IO.File]::ReadAllText($lease) -eq $Session) {
            $state = Read-Json (Join-Path $run 'state.json')
            if ($state.phase -eq 'starting') {
                $state = Result 'cancelled' 'task-did-not-start'
                Remove-Item -LiteralPath (Join-Path $run 'request.json') -ErrorAction SilentlyContinue
                Write-Json $state (Join-Path $run 'state.json')
                Remove-Item -LiteralPath $lease
            }
        }
        $state | ConvertTo-Json -Compress
    }
}
