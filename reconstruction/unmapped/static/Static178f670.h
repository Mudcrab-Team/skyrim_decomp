// Source exposure: binary-analysis; no external implementation source reused.
// Static178f670, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178f670;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178f670*);
    virtual void release(Static178f670*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178f670*);
struct Static178f670 {
    void* value;
    Static178f670();
    ~Static178f670() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
