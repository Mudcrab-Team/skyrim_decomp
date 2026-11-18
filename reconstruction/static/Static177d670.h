// Source exposure: binary-analysis; no external implementation source reused.
// Static177d670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177d670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177d670*);
    virtual void release(Static177d670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177d670*);
struct Static177d670 {
    void* value;
    Static177d670();
    ~Static177d670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
