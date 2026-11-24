# Lean drafter round brief template

Assign a fresh drafter to at most three functions in its assigned checkout. State the model,
task directories, RVAs, attempt cap, stop rule, permitted inputs, runner configuration and
handoff destination. Do not embed whole documents or private listings in the brief.

Read [drafter-essentials.md](drafter-essentials.md) once. For each RVA, run
`./sr sheet 0x<rva> --task <task-dir>` and `./sr lessons 0x<rva> --max-chars 12000`.
Tags are derived from available task and index facts; use `./sr lessons --tag wall/register-schedule` when a wall is diagnosed. Follow the card's
pointers to full documents when needed. For the private round score and permute tools, redirect their full output to a private file and read only the short summary needed. Keep exploratory shell output short, for example with
`head`; never print raw bytes or dumps. Work sequentially within the assigned cap and record
results, stop reasons, relevant rule hits and one-line bottlenecks with estimated time costs.
A new drafter starts with fresh context for the next group.
