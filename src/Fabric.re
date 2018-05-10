type iconProps = {. "iconName": string};

let createIconProps = (~iconName) => {"iconName": iconName};

/* Every Fabric component need to be initialize with this
        see point 2 at https://developer.microsoft.com/en-us/fabric#/get-started
   */
module Fabric = {
  [@bs.module "office-ui-fabric-react/lib/Fabric"]
  external reactClass : ReasonReact.reactClass = "Fabric";
  let make = children =>
    ReasonReact.wrapJsForReason(~reactClass, ~props=Js.Obj.empty(), children);
};

module ButtonUtils = {
  module DirectionalHint = {
    type t = [
      | `topCenter
      | `topRightEdge
      | `topAutoEdge
      | `bottomLeftEdge
      | `bottomCenter
      | `bottomRightEdge
      | `bottomAutoEdge
      | `leftTopEdge
      | `leftCenter
      | `leftBottomEdge
      | `rightTopEdge
      | `rightCenter
      | `rightBottomEdge
    ];
    /* Documentation https://github.com/OfficeDev/office-ui-fabric-react/blob/e405fefcbf48d7bd72e24a3231d4de1a2f4d3ec3/packages/office-ui-fabric-react/src/common/DirectionalHint.ts */
    let toJs = t =>
      switch (t) {
      | `topLeftEdge => 0
      | `topCenter => 1
      | `topRightEdge => 2
      | `topAutoEdge => 3
      | `bottomLeftEdge => 4
      | `bottomCenter => 5
      | `bottomRightEdge => 6
      | `bottomAutoEdge => 7
      | `leftTopEdge => 8
      | `leftCenter => 9
      | `leftBottomEdge => 10
      | `rightTopEdge => 11
      | `rightCenter => 12
      | `rightBottomEdge => 13
      };
  };
  module MenuProps = {
    type item = {
      key: string,
      name: string,
      onClick: ReactEventRe.Mouse.t => unit,
    };
    let _createItem = (~key, ~name, ~onClick) => {
      "key": key,
      "name": name,
      "onClick": onClick,
    };
    let createItems = items =>
      List.map(
        item =>
          _createItem(~key=item.key, ~name=item.name, ~onClick=item.onClick),
        items,
      )
      |> Array.of_list;
    let createMenuProps = (~shouldFocusOnMount, ~directionalHint, ~items) => {
      "shouldFocusOnMount": shouldFocusOnMount,
      "directionalHint": directionalHint |> DirectionalHint.toJs,
      "items": items,
    };
  };
};

module DefaultButton = {
  [@bs.module "office-ui-fabric-react/lib/Button"]
  external reactClass : ReasonReact.reactClass = "DefaultButton";
  let make =
      (
        ~text: option(string)=?,
        ~primary: option(bool)=?,
        ~disabled: option(bool)=?,
        ~iconProps: option(iconProps)=?,
        ~onClick: option(ReactEventRe.Mouse.t => unit)=?,
        ~menuProps: option(Js.t({..}))=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "text": fromOption(text),
            "primary": fromOption(primary),
            "disabled": fromOption(disabled),
            "iconProps": fromOption(iconProps),
            "onClick": fromOption(onClick),
            "menuProps": fromOption(menuProps),
          }
        ),
      children,
    );
};

module TextField = {
  type componentRef;
  type any;
  [@bs.module "office-ui-fabric-react/lib/TextField"]
  external _textField : ReasonReact.reactClass = "TextField";
  let make =
      (
        ~value: option(string)=?,
        ~label: option(string)=?,
        ~disabled: option(bool)=?,
        ~required: option(bool)=?,
        ~errorMessage: option(string)=?,
        ~ariaLabel: option(string)=?,
        ~placeholder: option(string)=?,
        ~borderless: option(bool)=?,
        ~className: option(string)=?,
        ~type_: option(string)=?,
        ~componentRef: option(componentRef => unit)=?,
        ~defaultValue as _: option(string)=?,
        ~deferredValidationTime: option(int)=?,
        ~description: option(string)=?,
        ~iconProps: option(iconProps)=?,
        ~inputClassName: option(string)=?,
        ~multiline: option(bool)=?,
        /* CB */
        ~onBeforeChange: option(any => unit)=?,
        ~onChanged: option(any => unit)=?,
        ~onGetErrorMessage: option(string => unit)=?,
        ~onNotifyValidationResult: option((string, string) => unit)=?,
        ~prefix: option(string)=?,
        ~resizable: option(bool)=?,
        ~suffix: option(string)=?,
        ~underlined: option(bool)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_textField,
      ~props=
        Js.Nullable.(
          {
            "value": fromOption(value),
            "label": fromOption(label),
            "disabled": fromOption(disabled),
            "required": fromOption(required),
            "errorMessage": fromOption(errorMessage),
            "ariaLabel": fromOption(ariaLabel),
            "placeholder": fromOption(placeholder),
            "borderless": fromOption(borderless),
            "className": fromOption(className),
            "type": fromOption(type_),
            "componentRef": fromOption(componentRef) /* "defaultValue": fromOption(defaultValue), */, /* there's a warning because using defaultValue and value that should be mutuailly exclusive each other */
            "deferredValidationTime": fromOption(deferredValidationTime),
            "description": fromOption(description),
            "iconProps": fromOption(iconProps),
            "inputClassName": fromOption(inputClassName),
            "multiline": fromOption(multiline),
            "onBeforeChange": fromOption(onBeforeChange),
            "onChanged": fromOption(onChanged),
            "onGetErrorMessage": fromOption(onGetErrorMessage),
            "onNotifyValidationResult": fromOption(onNotifyValidationResult),
            "prefix": fromOption(prefix),
            "suffix": fromOption(suffix),
            "resizable": fromOption(resizable),
            "underlined": fromOption(underlined),
          }
        ),
      children,
    );
};

module DocumentCard = {
  [@bs.module "office-ui-fabric-react/lib/DocumentCard"]
  external _documentCard : ReasonReact.reactClass = "DocumentCard";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_documentCard,
      ~props=Js.Obj.empty(),
      children,
    );
};

module IDocumentCardPreviewProps = {
  [@bs.module "office-ui-fabric-react/lib/DocumentCard"]
  external _iDocumentPreviewProps : ReasonReact.reactClass =
    "IDocumentCardPreviewProps";
  let make = children =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_iDocumentPreviewProps,
      ~props=Js.Obj.empty(),
      children,
    );
};

module DocumentCardPreview = {
  [@bs.module "office-ui-fabric-react/lib/DocumentCard"]
  external _documentCardPreview : ReasonReact.reactClass =
    "DocumentCardPreview";
  let previewPropsUsingIcon = {
    "previewImages": [
      {
        "previewIconProps": {
          "iconName": "OpenFile",
          "styles": {
            "root": {
              "fontSize": 42,
              "color": "#ffffff",
            },
          },
        },
        "width": 318,
        "height": 196,
      },
    ],
  };
  let make = (~previewImages=previewPropsUsingIcon##previewImages, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_documentCardPreview,
      ~props={"previewImages": previewImages},
      children,
    );
};

module DocumentCardTitle = {
  [@bs.module "office-ui-fabric-react/lib/DocumentCard"]
  external _documentCardTitle : ReasonReact.reactClass = "DocumentCardTitle";
  let make = (~title: string, ~shouldTruncate: option(bool)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_documentCardTitle,
      ~props=
        Js.Nullable.(
          {"title": title, "shouldTruncate": fromOption(shouldTruncate)}
        ),
      children,
    );
};

module DocumentCardActivity = {
  [@bs.module "office-ui-fabric-react/lib/DocumentCard"]
  external _documentCardActivity : ReasonReact.reactClass = "DocumentCard";
  [@bs.obj]
  external makeProps :
    (~activity: string, ~people: list({. "name": string})) => _ =
    "";
  let people = [{"name": "Kat Larrson"}];
  let make = (~activity: string, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_documentCardActivity,
      ~props=makeProps(~activity, ~people),
      children,
    );
};

module Icon = {
  [@bs.module "office-ui-fabric-react/lib/Icon"]
  external _icon : ReasonReact.reactClass = "Icon";
  let make =
      (~iconName: string, ~className: option(string)=?, ~styles=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_icon,
      ~props={
        "iconName": iconName,
        "className": Js.Nullable.fromOption(className),
        "styles": Js.Nullable.fromOption(styles),
      },
      children,
    );
};

module Persona = {
  [@bs.module "office-ui-fabric-react/lib/Persona"]
  external reactClass : ReasonReact.reactClass = "Persona";
  let make =
      (
        ~imageUrl: option(string)=?,
        ~primaryText: option(string)=?,
        ~secondaryText: option(string)=?,
        ~imageInitials: option(string)=?,
        ~showSecondaryText: option(bool)=?,
        ~style: option(ReactDOMRe.style)=?,
        children,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass,
      ~props=
        Js.Nullable.(
          {
            "imageUrl": fromOption(imageUrl),
            "primaryText": fromOption(primaryText),
            "secondaryText": fromOption(secondaryText),
            "imageInitials": fromOption(imageInitials),
            "showSecondaryText": fromOption(showSecondaryText),
            "styles": fromOption(style),
          }
        ),
      children,
    );
};

module SearchBox = {
  [@bs.module "office-ui-fabric-react/lib/SearchBox"]
  external _searchBox : ReasonReact.reactClass = "SearchBox";
  let make = (~placeholder: option(string)=?, children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=_searchBox,
      ~props=Js.Nullable.({"placeholder": fromOption(placeholder)}),
      children,
    );
};