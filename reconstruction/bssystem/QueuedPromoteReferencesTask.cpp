// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSDynamicPersistenceManager.cpp:47 (QueuedPromoteReferencesTask::Finish)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSDynamicPersistenceManager.cpp:59 (QueuedPromoteReferencesTask::Cancel)
// QueuedPromoteReferencesTask, Finish, Cancel, BGSDynamicPersistenceManager, instance, RemoveTask, state: GUESS(low)
// 0x204320 QueuedPromoteReferencesTask::Finish
// 0x204340 QueuedPromoteReferencesTask::Cancel
#include "QueuedPromoteReferencesTask.h"
void QueuedPromoteReferencesTask::Finish() { BGSDynamicPersistenceManager::instance->RemoveTask(this); }
void QueuedPromoteReferencesTask::Cancel(int state, void*) { if (state != 5) BGSDynamicPersistenceManager::instance->RemoveTask(this); }
