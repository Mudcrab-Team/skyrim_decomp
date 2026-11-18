// Source exposure: binary-analysis; no external implementation source reused.
// Static176f700, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f700;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f700*);
    virtual void release(Static176f700*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f700*);
struct Static176f700 {
    void* value;
    Static176f700();
    ~Static176f700() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
