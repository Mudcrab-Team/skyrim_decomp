// Source exposure: binary-analysis; no external implementation source reused.
// Static175f030, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f030;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f030*);
    virtual void release(Static175f030*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f030*);
struct Static175f030 {
    void* value;
    Static175f030();
    ~Static175f030() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
