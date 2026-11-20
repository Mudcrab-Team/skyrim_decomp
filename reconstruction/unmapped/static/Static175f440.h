// Source exposure: binary-analysis; no external implementation source reused.
// Static175f440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static175f440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static175f440*);
    virtual void release(Static175f440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static175f440*);
struct Static175f440 {
    void* value;
    Static175f440();
    ~Static175f440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
