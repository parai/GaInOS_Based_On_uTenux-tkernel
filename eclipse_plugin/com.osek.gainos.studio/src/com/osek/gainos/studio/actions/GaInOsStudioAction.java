package com.osek.gainos.studio.actions;

import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import org.eclipse.core.runtime.FileLocator;
import org.eclipse.core.runtime.IPath;
import org.eclipse.core.runtime.Platform;
import org.eclipse.jface.action.IAction;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.ui.IWorkbenchWindow;
import org.eclipse.ui.IWorkbenchWindowActionDelegate;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.osgi.service.datalocation.Location;

import com.osek.gainos.studio.Activator;

/**
 * Our sample action implements workbench action delegate.
 * The action proxy will be created by the workbench and
 * shown in the UI. When the user tries to use the action,
 * this delegate will be created and execution will be 
 * delegated to it.
 * @see IWorkbenchWindowActionDelegate
 */
public class GaInOsStudioAction implements IWorkbenchWindowActionDelegate {
	private IWorkbenchWindow window;
	/**
	 * The constructor.
	 */
	public GaInOsStudioAction() {
	}
	public void startMyStudio(String path)
	{       
        String cmd = "python F:/parai@foxmail.com/github/GaInOS_Based_On_uTenux-tkernel/gainos_studio/main.py --eclipse "; 
        
        cmd += path;
         
        Runtime run = Runtime.getRuntime();//返回与当前 Java 应用程序相关的运行时对象     
        try {     
            Process p = run.exec(cmd);// 启动另一个进程来执行命令         
        } catch (Exception e) {     
            e.printStackTrace();     
        }     
	}
	public String getIProjectPath()
	{
		IPath path;
		path = Platform.getLocation();
		return path.toString();
	}
	/**
	 * The action has been activated. The argument of the
	 * method represents the 'real' action sitting
	 * in the workbench UI.
	 * @see IWorkbenchWindowActionDelegate#run
	 */
	public void run(IAction action) {
		Location ins=Platform.getInstallLocation();
		String path = getIProjectPath();
		startMyStudio(path);
    }

	/**
	 * Selection in the workbench has been changed. We 
	 * can change the state of the 'real' action here
	 * if we want, but this can only happen after 
	 * the delegate has been created.
	 * @see IWorkbenchWindowActionDelegate#selectionChanged
	 */
	public void selectionChanged(IAction action, ISelection selection) {
	}

	/**
	 * We can use this method to dispose of any system
	 * resources we previously allocated.
	 * @see IWorkbenchWindowActionDelegate#dispose
	 */
	public void dispose() {
	}

	/**
	 * We will cache window object in order to
	 * be able to provide parent shell for the message dialog.
	 * @see IWorkbenchWindowActionDelegate#init
	 */
	public void init(IWorkbenchWindow window) {
		this.window = window;
	}
}


