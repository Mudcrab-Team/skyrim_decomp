// Source exposure: binary-analysis; no external implementation source reused.
// Static178f440, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f440;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f440*);
    virtual void release(Static178f440*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f440*);
struct Static178f440 {
    void* value;
    Static178f440();
    ~Static178f440() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
