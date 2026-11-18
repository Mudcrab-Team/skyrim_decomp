// Source exposure: binary-analysis; no external implementation source reused.
// Static174d670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static174d670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static174d670*);
    virtual void release(Static174d670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static174d670*);
struct Static174d670 {
    void* value;
    Static174d670();
    ~Static174d670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
