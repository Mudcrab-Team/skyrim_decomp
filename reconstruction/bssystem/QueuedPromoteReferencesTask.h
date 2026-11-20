// Source exposure: mixed (target listing, anonymous sibling and unverified names).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSDynamicPersistenceManager.cpp:47 (QueuedPromoteReferencesTask::Finish)
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/BGSDynamicPersistenceManager.cpp:59 (QueuedPromoteReferencesTask::Cancel)
// QueuedPromoteReferencesTask, Finish, Cancel, BGSDynamicPersistenceManager, instance, RemoveTask, state: GUESS(low)
#pragma once
class QueuedPromoteReferencesTask;
class BGSDynamicPersistenceManager { public: static BGSDynamicPersistenceManager* instance; void RemoveTask(QueuedPromoteReferencesTask*); };
class QueuedPromoteReferencesTask { public: void Finish(); void Cancel(int state, void*); };
