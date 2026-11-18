// Source exposure: binary-analysis; no external implementation source reused.
// Static1776690, Manager, manager, reserved, construct, release, value: GUESS(low) STANDIN
#pragma once
struct Static1776690;
struct Manager {
    virtual void reserved();
    virtual void construct(Static1776690*);
    virtual void release(Static1776690*);
};
extern Manager* manager();
// empty_resource, cleanup: GUESS(low) STANDIN
extern unsigned char empty_resource;
extern void cleanup(Static1776690*);
struct Static1776690 {
    void* value;
    Static1776690();
    ~Static1776690() { value = &empty_resource; manager()->release(this); cleanup(this); }
};
