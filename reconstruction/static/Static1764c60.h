// Source exposure: binary-analysis; no external implementation source reused.
// Static1764c60, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1764c60;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1764c60*);
    virtual void release(Static1764c60*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1764c60*);
struct Static1764c60 {
    void* value;
    Static1764c60();
    ~Static1764c60() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
