// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AnimationFileManagerSingleton; size 0xa0
#pragma once

#include "BSSpinLock.h"
#include "BSTArray_RE__AnimationFileManagerSingleton__LoadedAnimation_1eff2ec1.h"
#include "BSTArray_RE__AnimationFileManagerSingleton__QueuedAnimation_1f28c244.h"
#include "BSTArray_void_9eb8914c.h"
#include "BSTSingletonSDM_RE__AnimationFileManagerSingleton_b6649a44.h"
#include "IAnimationClipLoaderSingleton.h"
#include "LoadedAnimation.h"
struct AnimationFileManagerSingleton {
    IAnimationClipLoaderSingleton _base;
    BSTSingletonSDM_RE__AnimationFileManagerSingleton_b6649a44 _base_BSTSingletonSDM_RE_AnimationFileManagerSingleton_;
    unsigned char undefined_9[3];
    BSSpinLock lockA;
    unsigned char lockB_raw[12];
    LoadedAnimation currentAnimation;
    BSTArray_RE__AnimationFileManagerSingleton__QueuedAnimation_1f28c244 queuedAnimations;
    BSTArray_RE__AnimationFileManagerSingleton__LoadedAnimation_1eff2ec1 loadedAnimations;
    BSTArray_void_9eb8914c unk68;
    unsigned long long unk80;
    BSTArray_void_9eb8914c unk88;
};
static_assert(sizeof(AnimationFileManagerSingleton) == 160, "AnimationFileManagerSingleton layout differs from the PDB");
