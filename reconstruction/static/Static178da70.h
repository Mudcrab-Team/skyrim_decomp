// Source exposure: binary-analysis; no external implementation source reused.
// Static178da70, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178da70;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178da70*);
    virtual void release(Static178da70*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178da70*);
struct Static178da70 {
    void* value;
    Static178da70();
    ~Static178da70() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
