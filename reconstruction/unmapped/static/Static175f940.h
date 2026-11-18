// Source exposure: binary-analysis; no external implementation source reused.
// Static175f940, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f940;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f940*);
    virtual void release(Static175f940*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f940*);
struct Static175f940 {
    void* value;
    Static175f940();
    ~Static175f940() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
