// Source exposure: binary-analysis; no external implementation source reused.
// Static178a050, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178a050;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178a050*);
    virtual void release(Static178a050*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178a050*);
struct Static178a050 {
    void* value;
    Static178a050();
    ~Static178a050() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
