// Source exposure: binary-analysis; no external implementation source reused.
// Static173c670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static173c670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static173c670*);
    virtual void release(Static173c670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static173c670*);
struct Static173c670 {
    void* value;
    Static173c670();
    ~Static173c670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
