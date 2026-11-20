// Source exposure: binary-analysis; no external implementation source reused.
// Static176f480, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f480;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f480*);
    virtual void release(Static176f480*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f480*);
struct Static176f480 {
    void* value;
    Static176f480();
    ~Static176f480() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
