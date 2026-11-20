// Source exposure: binary-analysis; no external implementation source reused.
// Static178cd80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178cd80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178cd80*);
    virtual void release(Static178cd80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178cd80*);
struct Static178cd80 {
    void* value;
    Static178cd80();
    ~Static178cd80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
