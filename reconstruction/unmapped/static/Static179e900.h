// Source exposure: binary-analysis; no external implementation source reused.
// Static179e900, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static179e900;
struct Manager {
    virtual void reserved();
    virtual void construct(Static179e900*);
    virtual void release(Static179e900*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static179e900*);
struct Static179e900 {
    void* value;
    Static179e900();
    ~Static179e900() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
