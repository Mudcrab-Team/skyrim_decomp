// Source exposure: binary-analysis; no external implementation source reused.
// Static174b490, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174b490;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174b490*);
    virtual void release(Static174b490*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174b490*);
struct Static174b490 {
    void* value;
    Static174b490();
    ~Static174b490() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
