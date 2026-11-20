// Source exposure: binary-analysis; no external implementation source reused.
// Static178c100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178c100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178c100*);
    virtual void release(Static178c100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178c100*);
struct Static178c100 {
    void* value;
    Static178c100();
    ~Static178c100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
