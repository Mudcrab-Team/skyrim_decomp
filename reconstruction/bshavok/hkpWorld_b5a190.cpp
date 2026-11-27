// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast-noeh-root-includes.json
// 0xb5a190 hkpWorld::getClosestPoints
// Adapted bodies: none
#include "hkpWorld_b5a190.h"

// find everything near the collidable (broad phase or the trees) and report the closest points to the collector
void hkpWorld::getClosestPoints(const hkpCollidable* a_collidable, const hkpCollisionInput* a_input, void* a_collector) noexcept
{
    hkAabb aabb;
    a_collidable->shape->GetAabbImpl(a_collidable->motion, a_input->tolerance - collisionInput->tolerance * 0.5f, aabb);

    if (!kdTreeManager || !kdTreeManager->hasTrees()) {
        hkTimerBeginList(g_timerListBroadPhase, g_timer3AxisBroadPhase);
        hkInplaceArray<hkpTypedBroadPhaseHandlePair, 128> hits;
        broadPhase->querySingleAabb(aabb, &hits);
        const hkpTypedBroadPhaseHandlePair* pair = hits.data;
        const int typeA = a_collidable->shape->type;
        hkTimerSplitList(g_timer3AxisNarrowPhase);
        for (int i = hits.size - 1; i >= 0; --i) {
            const hkpCollidable* other = static_cast<const hkpCollidable*>(pair->b->getOwningObject());
            // skip the body itself and filtered pairs, then call the closest-point function of the two shape types
            if (a_collidable != other && collisionFilter->isCollisionEnabled(*a_collidable, *other) && other->shape) {
                const std::uint8_t agent = a_input->dispatcher->agent2Types[typeA][other->shape->type];
                a_input->dispatcher->agent2Func[agent].getClosestPointFunc(*a_collidable, *other, *a_input, a_collector);
            }
            ++pair;
        }
        hkTimerEndList();
    } else {
        hkTimerBeginList(g_timerListTrees, g_timerAabbTreeBroadPhase);
        void* aabbTree = kdTreeManager->inactiveTree;
        void* kdTree = kdTreeManager->kdTree;
        if (aabbTree) {
            hkInplaceArray<const hkpCollidable*, 128> hits;
            g_aabbTreeQueryAabb(aabbTree, &aabb, &hits);
            hkTimerSplitList(g_timerAabbTreeNarrowPhase);
            const int typeA = a_collidable->shape->type;
            for (int i = 0; i < hits.size; ++i) {
                const hkpCollidable* other = hits.data[i];
                if (a_collidable != other && collisionFilter->isCollisionEnabled(*a_collidable, *other) && other->shape) {
                    const std::uint8_t agent = a_input->dispatcher->agent2Types[typeA][other->shape->type];
                    a_input->dispatcher->agent2Func[agent].getClosestPointFunc(*a_collidable, *other, *a_input, a_collector);
                }
            }
        }
        if (kdTree) {
            hkTimerSplitList(g_timerKdTreeBroadPhase);
            hkTempArray<const hkpCollidable*> hits;
            g_kdTreeQueryAabb(kdTree, &aabb, &hits);
            hkTimerSplitList(g_timerKdTreeNarrowPhase);
            const int typeA = a_collidable->shape->type;
            for (int i = 0; i < hits.size; ++i) {
                const hkpCollidable* other = hits.data[i];
                if (a_collidable != other && collisionFilter->isCollisionEnabled(*a_collidable, *other) && other->shape) {
                    const std::uint8_t agent = a_input->dispatcher->agent2Types[typeA][other->shape->type];
                    a_input->dispatcher->agent2Func[agent].getClosestPointFunc(*a_collidable, *other, *a_input, a_collector);
                }
            }
        }
        hkTimerEndList();
    }
}
