// PlayerCharacterMembers: STANDIN GUESS(medium); typed windows into an external player receiver.
// Origin: original reconstruction using published project member declarations.
// Source exposure: mixed; member offsets are target-bound contracts, not a complete object layout.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// PlayerCharacterMembers, Get: STANDIN GUESS(medium); access to the named member window of an external receiver.
#pragma once
#include "skyrim_shared/actors/PlayerCharacterTargetMembers.h"
namespace P2072 {
class PlayerCharacterMembers {
public:
    template<class T, class Binding>
    static T& Get(void* receiver) {
        return *reinterpret_cast<T*>(reinterpret_cast<std::uint8_t*>(receiver) + Binding::offset);
    }
};
}
