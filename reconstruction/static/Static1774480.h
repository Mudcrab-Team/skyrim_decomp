// Source exposure: binary-analysis; no external implementation source reused.
// Static1774480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1774480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1774480*);
    virtual void release(Static1774480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1774480*);
struct Static1774480 {
    void* value;
    Static1774480();
    ~Static1774480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
