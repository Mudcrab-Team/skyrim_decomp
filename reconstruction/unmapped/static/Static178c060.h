// Source exposure: binary-analysis; no external implementation source reused.
// Static178c060, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c060;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c060*);
    virtual void release(Static178c060*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c060*);
struct Static178c060 {
    void* value;
    Static178c060();
    ~Static178c060() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
