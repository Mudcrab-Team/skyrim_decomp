// Source exposure: binary-analysis; no external implementation source reused.
// Static178bcf0, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178bcf0;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178bcf0*);
    virtual void release(Static178bcf0*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178bcf0*);
struct Static178bcf0 {
    void* value;
    Static178bcf0();
    ~Static178bcf0() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
