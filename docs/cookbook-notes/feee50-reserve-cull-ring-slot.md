# 0xfeee50 CullQueue::PushQueueEntry

<!-- tags: construct/loop, wall/control-flow -->

- Function: 0xfeee50 CullQueue::PushQueueEntry
- Label: GUESS(low)
- Outcome: fixed
- Cause: loop-shape
- Best score: 194/194 aligned matching bytes
- Attempts: 3

## What differed

The producer and consumer reserve indices independently of publishing completion. Retrying from the top of the loop changed where the cursor was reloaded.

## Spellings tried that did not help

A single unconditional reload at loop entry changed the retry branch.

## Spelling that fixed it

Read the initial cursor before entering the loop. On a full queue yield and refresh it. Refresh it again on the failed reservation path. The consumer uses the same retry structure at 0xfeef70.
