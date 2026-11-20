// Source exposure: binary-analysis; no external implementation source reused.
// Static178c830, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c830;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c830*);
    virtual void release(Static178c830*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c830*);
struct Static178c830 {
    void* value;
    Static178c830();
    ~Static178c830() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
