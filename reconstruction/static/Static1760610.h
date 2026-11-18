// Source exposure: binary-analysis; no external implementation source reused.
// Static1760610, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1760610;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1760610*);
    virtual void release(Static1760610*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1760610*);
struct Static1760610 {
    void* value;
    Static1760610();
    ~Static1760610() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
