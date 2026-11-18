// Source exposure: binary-analysis; no external implementation source reused.
// Static173f460, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173f460;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173f460*);
    virtual void release(Static173f460*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173f460*);
struct Static173f460 {
    void* value;
    Static173f460();
    ~Static173f460() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
