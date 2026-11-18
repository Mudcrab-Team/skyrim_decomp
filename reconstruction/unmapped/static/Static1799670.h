// Source exposure: binary-analysis; no external implementation source reused.
// Static1799670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1799670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1799670*);
    virtual void release(Static1799670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1799670*);
struct Static1799670 {
    void* value;
    Static1799670();
    ~Static1799670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
