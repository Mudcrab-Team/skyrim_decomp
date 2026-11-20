// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MapMenu; size 0x30598
#pragma once

#include "BSSoundHandle.h"
#include "BSTArray_RE__GFxValue_2c1e4183.h"
#include "BSTArray_RE__MapMenuMarker_591ae6e2.h"
#include "BSTEventSink_RE__MenuOpenCloseEvent_dbada304.h"
#include "BSTSmartPointer_RE__MapLookHandler_74421607.h"
#include "BSTSmartPointer_RE__MapMoveHandler_70c311d6.h"
#include "BSTSmartPointer_RE__MapZoomHandler_aa589f37.h"
#include "GFxValue.h"
#include "IMapCameraCallbacks.h"
#include "IMenu_09c1ffe2.h"
#include "LocalMapMenu.h"
#include "MapCamera.h"
#include "NiPoint3.h"
struct TESWorldSpace;
struct MapMenu {
    IMenu_09c1ffe2 _base;
    BSTEventSink_RE__MenuOpenCloseEvent_dbada304 _base_BSTEventSink_RE_MenuOpenCloseEvent_;
    IMapCameraCallbacks _base_IMapCameraCallbacks;
    BSTSmartPointer_RE__MapMoveHandler_70c311d6 moveHandler;
    BSTSmartPointer_RE__MapLookHandler_74421607 lookHandler;
    BSTSmartPointer_RE__MapZoomHandler_aa589f37 zoomHandler;
    unsigned char mapMarker_raw[8];
    LocalMapMenu localMapMenu;
    unsigned int cameraRootRef;
    NiPoint3 playerMarkerPosition;
    BSTArray_RE__MapMenuMarker_591ae6e2 mapMarkers;
    BSTArray_RE__GFxValue_2c1e4183 markerData;
    MapCamera camera;
    unsigned long long unk30530;
    TESWorldSpace* worldSpace;
    GFxValue mapMovie;
    int selectedMarker;
    NiPoint3 cameraPickOrigin;
    NiPoint3 cameraPickDirection;
    BSSoundHandle unk30574;
    unsigned long long unk30580;
    unsigned int unk30588;
    bool controlsReady;
    unsigned char unk3058D;
    unsigned short unk3058E;
    unsigned long long unk30590;
};
static_assert(sizeof(MapMenu) == 198040, "MapMenu layout differs from the PDB");
