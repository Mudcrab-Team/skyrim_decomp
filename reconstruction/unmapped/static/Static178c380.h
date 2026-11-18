// Source exposure: binary-analysis; no external implementation source reused.
// Static178c380, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c380;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c380*);
    virtual void release(Static178c380*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c380*);
struct Static178c380 {
    void* value;
    Static178c380();
    ~Static178c380() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
