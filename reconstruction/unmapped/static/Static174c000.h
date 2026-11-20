// Source exposure: binary-analysis; no external implementation source reused.
// Static174c000, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174c000;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174c000*);
    virtual void release(Static174c000*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174c000*);
struct Static174c000 {
    void* value;
    Static174c000();
    ~Static174c000() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
