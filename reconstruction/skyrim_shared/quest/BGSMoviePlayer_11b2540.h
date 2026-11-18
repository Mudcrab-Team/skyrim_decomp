/*
 * BGSMoviePlayer: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x11b2540 26 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * No external body or declaration has yet been adapted. Stand-ins are unverified.
 */
// BGSMoviePlayer: GUESS(low) STANDIN
#pragma once
// BGSMoviePlayer, Function11b2540, MovieRegistry, Register, registry: GUESS(low) STANDIN
class BGSMoviePlayer;
class MovieRegistry { public: void Register(BGSMoviePlayer*); };
extern MovieRegistry* registry;
class BGSMoviePlayer { public: int Function11b2540(); };
