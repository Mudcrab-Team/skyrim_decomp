// Source exposure: binary-analysis; no external implementation source reused.
// Static178ec80, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static178ec80;
struct Manager {
    virtual void reserved();
    virtual void construct(Static178ec80*);
    virtual void release(Static178ec80*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static178ec80*);
struct Static178ec80 {
    void* value;
    Static178ec80();
    ~Static178ec80() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
