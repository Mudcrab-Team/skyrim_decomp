// Source exposure: binary-analysis; no external implementation source reused.
// Static177f100, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static177f100;
struct Manager {
    virtual void reserved();
    virtual void construct(Static177f100*);
    virtual void release(Static177f100*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static177f100*);
struct Static177f100 {
    void* value;
    Static177f100();
    ~Static177f100() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
