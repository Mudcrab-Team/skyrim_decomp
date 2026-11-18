// Source exposure: binary-analysis; no external implementation source reused.
// Static1776960, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776960;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776960*);
    virtual void release(Static1776960*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776960*);
struct Static1776960 {
    void* value;
    Static1776960();
    ~Static1776960() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
