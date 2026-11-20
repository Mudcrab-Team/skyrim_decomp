// Source exposure: binary-analysis; no external implementation source reused.
// Static178ca60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ca60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ca60*);
    virtual void release(Static178ca60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ca60*);
struct Static178ca60 {
    void* value;
    Static178ca60();
    ~Static178ca60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
