// Source exposure: binary-analysis; no external implementation source reused.
// Static1750620, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1750620;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1750620*);
    virtual void release(Static1750620*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1750620*);
struct Static1750620 {
    void* value;
    Static1750620();
    ~Static1750620() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
