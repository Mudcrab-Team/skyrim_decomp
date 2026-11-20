// Source exposure: binary-analysis; no external implementation source reused.
// Static174e890, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174e890;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174e890*);
    virtual void release(Static174e890*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174e890*);
struct Static174e890 {
    void* value;
    Static174e890();
    ~Static174e890() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
