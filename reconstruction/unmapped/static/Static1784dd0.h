// Source exposure: binary-analysis; no external implementation source reused.
// Static1784dd0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1784dd0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1784dd0*);
    virtual void release(Static1784dd0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1784dd0*);
struct Static1784dd0 {
    void* value;
    Static1784dd0();
    ~Static1784dd0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
