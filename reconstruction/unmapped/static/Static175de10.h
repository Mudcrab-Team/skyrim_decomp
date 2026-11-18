// Source exposure: binary-analysis; no external implementation source reused.
// Static175de10, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175de10;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175de10*);
    virtual void release(Static175de10*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175de10*);
struct Static175de10 {
    void* value;
    Static175de10();
    ~Static175de10() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
