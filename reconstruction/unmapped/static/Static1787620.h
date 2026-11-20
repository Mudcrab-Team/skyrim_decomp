// Source exposure: binary-analysis; no external implementation source reused.
// Static1787620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1787620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1787620*);
    virtual void release(Static1787620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1787620*);
struct Static1787620 {
    void* value;
    Static1787620();
    ~Static1787620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
