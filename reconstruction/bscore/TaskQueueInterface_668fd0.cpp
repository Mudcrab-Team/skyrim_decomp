// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// TaskQueueInterface::QueueForceWeather: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueRemoveSpell: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// TaskQueueInterface::QueueActorDisarm: SIBLING(fo4-private@1b765c70, author-permission); adapted task construction.
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1134
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1022
// Sibling source: fo4-private@1b765c70 src/Game/Misc/TaskQueueInterface.cpp:1476
// 0x669110 TaskQueueInterface::QueueForceWeather
// 0x668fd0 TaskQueueInterface::QueueRemoveSpell
// 0x6695d0 TaskQueueInterface::QueueActorDisarm
#include "TaskQueueInterface_668fd0.h"
void TaskQueueInterface::QueueForceWeather(TESWeather* weather, bool overrideWeather) {
    BSPackedTask task;
    task.data[0].integer = 0x40;
    task.data[1].pointer = weather;
    task.data[2].boolean = overrideWeather;
    QueueIfActive(task);
}
void TaskQueueInterface::QueueRemoveSpell(ActorHandle& target, SpellItem* spell) {
    BSPackedTask task;
    task.data[0].integer = 0x5d;
    task.data[1].integer = target.bits;
    task.data[2].pointer = spell;
    QueueIfActive(task);
}
void TaskQueueInterface::QueueActorDisarm(ActorHandle& target, ActorHandle& attacker) {
    BSPackedTask task;
    task.data[1].integer = target.bits;
    task.data[2].integer = attacker.bits;
    task.data[0].integer = 0x5b;
    QueueIfActive(task);
}
