// Code origin: declarations extended by hand from the local listings; names follow the community headers.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// Projectile, GetWeaponSpeedMult: GUESS(low)
// IsMissileProjectile, IsGrenadeProjectile: COMMUNITY(powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944, GPL-3.0); names only, the bodies are written from the target listing
#pragma once
class Projectile {
public:
    virtual bool IsMissileProjectile() const;
    virtual bool IsGrenadeProjectile() const;
    float GetWeaponSpeedMult() const;
};
