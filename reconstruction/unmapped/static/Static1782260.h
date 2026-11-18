// Source exposure: binary-analysis; no external implementation source reused.
// Static1782260, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1782260;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1782260*);
    virtual void release(Static1782260*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1782260*);
struct Static1782260 {
    void* value;
    Static1782260();
    ~Static1782260() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
