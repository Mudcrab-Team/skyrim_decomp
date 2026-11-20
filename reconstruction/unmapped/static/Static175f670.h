// Source exposure: binary-analysis; no external implementation source reused.
// Static175f670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f670*);
    virtual void release(Static175f670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f670*);
struct Static175f670 {
    void* value;
    Static175f670();
    ~Static175f670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
