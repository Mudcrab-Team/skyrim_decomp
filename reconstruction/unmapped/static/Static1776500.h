// Source exposure: binary-analysis; no external implementation source reused.
// Static1776500, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776500;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776500*);
    virtual void release(Static1776500*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776500*);
struct Static1776500 {
    void* value;
    Static1776500();
    ~Static1776500() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
