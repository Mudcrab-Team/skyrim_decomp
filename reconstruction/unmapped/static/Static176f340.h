// Source exposure: binary-analysis; no external implementation source reused.
// Static176f340, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static176f340;
struct Manager {
    virtual void reserved();
    virtual void construct(Static176f340*);
    virtual void release(Static176f340*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static176f340*);
struct Static176f340 {
    void* value;
    Static176f340();
    ~Static176f340() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
