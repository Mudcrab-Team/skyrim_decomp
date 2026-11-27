// CI hash: 0x14e9d20 ??_GBSTreeNode@@UEAAPEAXI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTreeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// 0x14e9d20 BSTreeNode::~BSTreeNode
#include "BSTreeNode_14e9d20.h"

// Emit the class vftable and scalar deleting destructor.
BSTreeNode::BSTreeNode() = default;

// Destroy the tree node and release both child arrays.
BSTreeNode::~BSTreeNode() {}
