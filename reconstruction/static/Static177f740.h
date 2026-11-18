// Source exposure: binary-analysis; no external implementation source reused.
// Static177f740, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f740;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f740*);
    virtual void release(Static177f740*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f740*);
struct Static177f740 {
    void* value;
    Static177f740();
    ~Static177f740() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
