// Source exposure: binary-analysis; no external implementation source reused.
// Static175de60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175de60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175de60*);
    virtual void release(Static175de60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175de60*);
struct Static175de60 {
    void* value;
    Static175de60();
    ~Static175de60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
