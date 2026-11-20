// Source exposure: binary-analysis; no external implementation source reused.
// Static17ab240, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static17ab240;
struct Manager {
    virtual void reserved();
    virtual void construct(Static17ab240*);
    virtual void release(Static17ab240*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static17ab240*);
struct Static17ab240 {
    void* value;
    Static17ab240();
    ~Static17ab240() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
